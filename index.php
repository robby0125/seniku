<?php
session_start();

if (isset($_COOKIE['rmi'])) {
    require_once 'controllers/auth_controller.php';

    $privateKey = hash('sha512', 'thisisprivate');
    $userId = explode($privateKey, $_COOKIE['rmi'])[1];
    $user = AuthController::getInstance()->getUserById($userId);
    $_SESSION['UserLogin'] = $user;
}

if (!isset($_SESSION['UserLogin'])) {
    header('Location: login.php');
    exit;
}

include 'assets/views/home.inc';