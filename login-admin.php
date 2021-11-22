<?php
include "assets/views/login-admin.inc";

include "#";

session_start();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $email = mysqli_real_escape_string($mysqli, $_POST['email']);
    $password = mysqli_real_escape_string($mysqli, md5($_POST['password']));

    $query = "SELECT * FROM users WHERE email= '$email' AND password = '$password'";
    $queryDB = mysqli_query($mysqli, $query);
    $check = mysqli_num_rows($queryDB);

    if ($check > 0) {
        // ambil data admin
        $getData = mysqli_fetch_array($queryDB);
        // set session 
        $_SESSION['name'] = $getData;
        $_SESSION['is_login']  = true;

        header("location: admin.php");
    } else {
        echo "The email or password you entered is incorrect";
    }
} else {
    return "You are not allowed";
}