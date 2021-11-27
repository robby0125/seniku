<?php
require_once 'controllers/auth_controller.php';

$authController = AuthController::getInstance();

if (isset($_GET['add'])) {
    require_once 'controllers/friend_controller.php';

    $curUserId = $_SESSION['UserLogin']['id'];

    $targetUser = $authController->getUserByUsername($_GET['add']);
    $targetUserId = $targetUser[0]['id'];

    $friendController = FriendController::getInstance();
    $friendController->addFriend($curUserId, $targetUserId);

    die;
}

if (!isset($_GET['username'])) {
    header('Location: index.php');
    exit;
}

$users = $authController->getUserByUsername($_GET['username']);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Search Result - Seniku</title>
    <link rel="stylesheet" href="assets/styles/style.css">
    <link rel="stylesheet" href="assets/styles/appbar.css">
    <link rel="stylesheet" href="assets/styles/search-user.css">
</head>

<body>
    <?php include 'assets/views/components/appbar.inc' ?>
    <main>
        <?php if (empty($users)) : ?>
            <h1 id="empty-text">Empty result.</h1>
        <?php else : ?>
            <h1 id="txt-result">Search Result</h1>
            <div id="users-container">
                <?php foreach ($users as $user) : ?>
                    <div class="user-card">
                        <img class="user-picture" src="assets/images/nophoto.jpg" alt="user picture">
                        <section class="name">
                            <h5 class="user-main-text"><?= $user['fullname'] ?></h5>
                            <h6 class="user-sub-text">@<?= $user['username'] ?></h6>
                        </section>
                        <section class="user-info">
                            <div class="info-part">
                                <h5 class="user-main-text">0</h5>
                                <h6 class="user-sub-text">Friends</h6>
                            </div>
                            <div class="vertical-line"></div>
                            <div class="info-part">
                                <h5 class="user-main-text">0</h5>
                                <h6 class="user-sub-text">Posts</h6>
                            </div>
                        </section>
                        <a class="action-button" href="search-user.php?add=<?= $user['username'] ?>">Add Friend</a>
                    </div>
                <?php endforeach; ?>
            </div>
        <?php endif; ?>
    </main>
</body>

</html>