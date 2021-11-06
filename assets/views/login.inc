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
        <form action="" method="post">
            <div class="field">
                <label class="nunito" for="email">Username or email</label>
                <input type="text" name="email" id="email">
            </div>
            <div class="field">
                <label class="nunito" for="password">Password</label>
                <input type="password" name="password" id="password">
            </div>
            <div class="field">
                <input type="checkbox" name="remember_me" id="remember_me">
                <label class="nunito" for="remember_me">Remember me</label>
            </div>
            <div class="field">
                <input type="submit" value="LOGIN">
            </div>
        </form>
        <p class="register nunito">Don't have an account? <a href="register.php">Register here</a></p>
        <p class="copyright nunito">Copyright &copy; 2021 Seniku Team</p>
    </div>
</body>

</html>