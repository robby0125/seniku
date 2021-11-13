<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Register - Seniku</title>
    <link rel="stylesheet" href="assets/styles/style.css">
    <link rel="stylesheet" href="assets/styles/register.css">
</head>
<body>
    <h1 class="title">Seniku</h1>
    <div class="form-container">
        <h2 class="poppins">Member Registration</h2>
        <form action="<?= $_SERVER['PHP_SELF']; ?>" method="POST">
            <div class="field">
                <label class="nunito" for="fullname">Full name</label>
                <input type="text" name="fullname" id="fullname" placeholder="Enter your full name">
            </div>
            <div class="field">
                <label class="nunito" for="username">Username</label>
                <input type="text" name="username" id="username" placeholder="Enter your username. e.g: seniku123">
            </div>
            <div class="field">
                <label class="nunito" for="email">Email</label>
                <input type="text" name="email" id="email" placeholder="Enter your email">
            </div>
            <div class="field">
                <label class="nunito" for="password">Password</label>
                <input type="password" name="password" id="password" placeholder="Enter your password at least 6 character">
            </div>
            <div class="field">
                <label class="nunito" for="gender">Gender</label>
                <select name="gender" id="gender">
                    <option value="" selected disabled>-- Choose your gender --</option>
                    <option value="Male">Male</option>
                    <option value="Female">Female</option>
                </select>
            </div>
            <div class="field">
                <label class="nunito" for="phone">Phone number</label>
                <input type="text" name="phone" id="phone" placeholder="Enter your phone number. e.g: 081123456789">
            </div>
            <div class="field">
                <label class="nunito" for="birth">Date of birth</label>
                <input type="date" name="birth" id="birth">
            </div>
            <input type="submit" name="register" value="REGISTER">
        </form>
    </div>
    <p class="sign-in nunito">Don't have an account? <a href="login.php">Login</a></p>
</body>
</html>