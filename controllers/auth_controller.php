<?php
require_once 'connection.php';

/**
 * this classs will handle all of authentication method
 * controller class created using singleton pattern
 */
class AuthController extends Connection
{
    private ?string $error = null;

    private static $instance = null;

    /**
     * protect the constructor method to avoid create new instance
     */
    protected function __construct()
    {
    }

    /**
     * get the single instance from AuthController class
     * @return AuthController object
     */
    public static function getInstance()
    {
        if (self::$instance == null) self::$instance = new AuthController();

        return self::$instance;
    }

    /**
     * this method will be handle login process
     * @param userIdentity = username or email of user
     * @param password = userpassword
     * @return return user info is login success
     */
    public function login($userIdentity, $password) : ?array
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
            $userInfo = $result->fetch(PDO::FETCH_ASSOC);

            if (password_verify($password, $userInfo['password'])) {
                if (!$this->error) $this->error = null;

                return $userInfo;
            } else {
                $this->error = 'Wrong password!';
            }
        } else {
            $this->error = 'Username/email not found!';
        }

        return null;
    }

    /**
     * this method will be handle register
     * @param fullname fullname of new user
     * @param username username of new user
     * @param email email of new user
     * @param password password of new user
     * @param gender gender of new user
     * @param phone phone number of new user
     * @param birthday birthday date of new user
     */
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

    /**
     * get specific user by id
     * @param id user id 
     * @return Object all of user info
     */
    public function getUserById($id) {
        $sql = 'SELECT * FROM user WHERE id = :id';
        $result = $this->getConnection()->prepare($sql);
        $result->bindValue(':id', $id);
        $result->execute();

        return $result->fetch(PDO::FETCH_ASSOC);
    }

    /**
     * get all user with constain piece of username
     * @param username piece of username
     * @return Object all list user
     */
    public function getUserByUsername($username) {
        $sql = 'SELECT * FROM user WHERE username LIKE :username';
        $result = $this->getConnection()->prepare($sql);
        $result->bindValue(':username', "%$username%");
        $result->execute();

        return $result->fetchAll(PDO::FETCH_ASSOC);
    }

    /**
     * get the error message
     */
    public function getError() : ?string {
        return $this->error;
    }
}
