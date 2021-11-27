<?php
session_start();

if (isset($_SESSION['UserLogin']) || isset($_COOKIE['rmi'])) {
    header('Location: index.php');
    exit;
}

if (isset($_POST['login'])) {

    require_once 'utils/validator.php';

    $validator = Validator::getInstance();

    foreach ($_POST as $key => $value) {
        if ($key != 'login') {
            $validator->validateEmpty($key, $value);
        }
    }

    $error = $validator->getError();

    if (!isset($error['password']))
        $validator->validateLength('password', $_POST['password'], 6, 'Password must be at least 6 characters.');

    if (!isset($error['email']) && !isset($error['password'])) {
        require_once 'controllers/auth_controller.php';

        $authController = AuthController::getInstance();
        $loginResult = $authController->login($_POST['email'], $_POST['password']);

        if ($loginResult) {
            if (isset($_POST['remember_me'])) {
                $id = $loginResult['id'];
                $privateKey = hash('sha512', 'thisisprivate');

                $hash_id = hash('sha256', $id) . $privateKey . $id;

                // rmi = remember me id
                setcookie('rmi', $hash_id, time() + 31536000);
                setcookie('test', hash('md5', 'inirahasia'), time() + 60);
            }

            $_SESSION['UserLogin'] = $loginResult;

            header('Location: index.php');
            exit;
        }
    }
}

include 'assets/views/login.inc';
