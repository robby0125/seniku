<?php
if (isset($_POST['login'])) {
    require_once 'utils/validator.php';

    $validator = Validator::getInstance();

    foreach ($_POST as $key => $value) {
        if ($key != 'login') {
            $validator->validateEmpty($key, $value);
        }
    }

    $error = $validator->getError();

    if (!isset($error['email']))
        $validator->validateEmail('email', $_POST['email']);

    if (!isset($error['password']))
        $validator->validateLength('password', $_POST['password'], 6, 'Password must be at least 6 characters.');
}

include 'assets/views/login.inc';
