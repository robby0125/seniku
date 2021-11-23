<?php
require_once 'connection.php';

class AuthController extends Connection
{
    private static $instance = null;

    protected function __construct()
    {
    }

    public static function getInstance()
    {
        if (self::$instance == null) self::$instance = new AuthController();

        return self::$instance;
    }

    public function login($userIdentity, $password)
    {
        $useEmail = filter_var($userIdentity, FILTER_VALIDATE_EMAIL);

        $sql = '';

        if ($useEmail) {
            $sql = 'SELECT * FROM user WHERE email = :userIdentity';
        } else {
            $sql = 'SELECT * FROM user WHERE username = :userIdentity';
        }

        $result = $this->getConnection()->prepare($sql);
        $result->bindValue(':userIdentity', $userIdentity);
        $result->execute();
        
        if ($result->rowCount() == 1) {
            $userInfo = $result->fetch();

            if (password_verify($password, $userInfo['password'])) {
                return $userInfo;
            } else {
                return 'Wrong password!';
            }
        } else {
            return 'Username/email not found!';
        }
    }

    public function register($fullname, $username, $email, $password, $gender, $phone, $birthday)
    {
        require_once 'utils/role.php';

        $result = $this->getConnection()->prepare("INSERT INTO user(role, email, password, fullname, username, gender, phone, birthday, registered_date) VALUES(:role, :email, :password, :fullname, :username, :gender, :phone, :birthday, CURRENT_DATE())");
        $result->bindValue(':role', Role::MEMBER);
        $result->bindValue(':email', $email);
        $result->bindValue(':password', $password);
        $result->bindValue(':fullname', $fullname);
        $result->bindValue(':username', $username);
        $result->bindValue(':gender', $gender);
        $result->bindValue(':phone', $phone);
        $result->bindValue(':birthday', $birthday);
        $result->execute();
    }

    public function getUserById($id) {
        $sql = 'SELECT * FROM user WHERE id = :id';
        $result = $this->getConnection()->prepare($sql);
        $result->bindValue(':id', $id);
        $result->execute();

        return $result->fetch();
    }
}
