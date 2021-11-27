<?php
$user = $_SESSION['UserLogin'];
$fullname = $user['fullname'];
$firstName = explode(' ', $fullname)[0];

$searchValue = '';

if (isset($_GET['username'])) $searchValue = htmlspecialchars($_GET['username']);
?>

<header>
    <nav>
        <a href="index.php">Seniku</a>
        <form class="search-user-form" action="search-user.php" method="GET">
            <input type="text" name="username" id="username" placeholder="Search username..." value="<?= $searchValue; ?>">
            <button type="submit">
                <img src="assets/icons/search-solid.png" alt="Search Icon">
            </button>
        </form>
        <div class="user">
            <p><?= $firstName; ?></p>
            <img src="assets/images/nophoto.jpg" alt="user picture">
        </div>
    </nav>
</header>