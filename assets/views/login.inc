<?php
$hasLogin = isset($_POST['login']);

if ($hasLogin) {
    require_once 'utils/validator.php';
    require_once 'controllers/auth_controller.php';

    $validator = Validator::getInstance();
    $error = $validator->getError();

    $authErrorMsg = AuthController::getInstance()->getError();
}

$curEmail = '';

if (isset($_POST['email'])) $curEmail = htmlspecialchars($_POST['email']);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login - Seniku</title>
    <link rel="stylesheet" href="assets/styles/style.css">
    <link rel="stylesheet" href="assets/styles/login.css">
</head>

<body>
    <div class="left-side">
        <h1 class="poppins">Welcome to <span class="title">Seniku</span></h1>
        <div class="horizontal-line"></div>
        <h2 class="nunito">Show off your art to the world</h2>
    </div>
    <div class="right-side">
        <h1 class="poppins">Hey there!</h1>
        <h2 class="nunito">Please login to continue!</h2>
        <?php if ($hasLogin && isset($authErrorMsg)) : ?>
            <p class="box-error"><?= $authErrorMsg; ?></p>
        <?php endif; ?>
        <form action="<?= $_SERVER['PHP_SELF']; ?>" method="POST">
            <div class="field">
                <label class="nunito" for="email">Username or email</label>
                <input type="text" name="email" id="email" value="<?= $curEmail; ?>">
                <?php if (isset($error['email'])) : ?>
                    <p class="error-message"><?= $error['email']; ?></p>
                <?php endif; ?>
            </div>
            <div class="field">
                <label class="nunito" for="password">Password</label>
                <input type="password" name="password" id="password">
                <?php if (isset($error['password'])) : ?>
                    <p class="error-message"><?= $error['password']; ?></p>
                <?php endif; ?>
            </div>
            <div class="field">
                <input type="checkbox" name="remember_me" id="remember_me">
                <label class="nunito" for="remember_me">Remember me</label>
            </div>
            <div class="field">
                <input type="submit" name="login" value="LOGIN">
            </div>
        </form>
        <p class="register nunito">Don't have an account? <a href="register.php">Register here</a></p>
        <p class="copyright nunito">Copyright &copy; 2021 Seniku Team</p>
    </div>
</body>

</html>