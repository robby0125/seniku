<?php
session_start();

if (isset($_SESSION['UserLogin'])) {
    if (isset($_COOKIE['rmi'])) {
        setcookie('rmi', '', time() - 3600);
    }

    session_unset();
    $_SESSION = [];
    session_destroy();
}

header('Location: login.php');
exit;
