<?php
class Validator
{
    private static $instance = null;
    private $error = [];

    protected function __construct()
    {
    }

    public static function getInstance()
    {
        if (self::$instance == null) self::$instance = new Validator();

        return self::$instance;
    }

    public function getError() {
        return $this->error;
    }

    public function validateEmpty($fieldName, $value) {
        if (!isset($value) || empty($value)) {
            $this->error[$fieldName] = 'This field can\'t be empty.';
        }
    }

    public function validateEmail($fieldName, $email) {
        if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $this->error[$fieldName] = "Email is invalid.";
        }
    }

    public function validateLength($fieldName, $value, $reqLength, $errMessage) {
        if (strlen($value) < $reqLength) {
            $this->error[$fieldName] = $errMessage;
        }
    }
}
