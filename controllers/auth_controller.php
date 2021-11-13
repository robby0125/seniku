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

    public function login($userIdentity, $password) {
        $useEmail = filter_var($userIdentity, FILTER_VALIDATE_EMAIL);
        $userFound = false;

        if ($useEmail) {
            $result = $this->getConnection()->prepare('SELECT * FROM user WHERE email = :email');
            $result->bindValue(':email', $userIdentity);
            $result->execute();
            var_dump($result);
        }
    }

    public function register($fullname, $username, $email, $password, $gender, $phone, $birthday) {
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
}
