<?php
if (isset($_POST['register'])) {
    require_once 'controllers/auth_controller.php';

    $fullname = $_POST['fullname'];
    $username = $_POST['username'];
    $email = $_POST['email'];
    $password = password_hash($_POST['password'], PASSWORD_DEFAULT);
    $gender = $_POST['gender'];
    $phone = $_POST['phone'];
    $birthday = $_POST['birth'];

    $authController = AuthController::getInstance();
    $authController->register($fullname, $username, $email, $password, $gender, $phone, $birthday);
}

include 'assets/views/register.inc';