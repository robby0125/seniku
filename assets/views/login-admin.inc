<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>admin login seniku</title>
    <style>
        h1,
        p {
            text-align: center;
        }

        body {
            display: flex;
            background-color: #FF7651;

        }

        .wrapper {
            width: 400px;
            box-shadow: 1px 2px 4px rgba(0, 0, 0, .5);
            background-color: white;
            margin: 10% auto;
            padding: 40px;
        }

        form input {
            width: 100%;
            height: 40px;
            border: 1px solid black;
            padding: 5px;
        }
    </style>
</head>

<body>
    <div class="wrapper">
        <h1>Login Admin Seniku</h1>
        <form action="proses_login.php" method="POST">
            <p>
                <input type="email" placeholder="Email" name="email">
            </p>
            <p>
                <input type="password" placeholder="Password" name="password">
            </p>
            <p>
                <input type="submit" value="Login">
            </p>
            <p>
                Don't have an account? <a href="register">Register here</a>
            </p>

        </form>
    </div>
</body>

</html>