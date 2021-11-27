<?php
require_once 'controllers/auth_controller.php';
require_once 'controllers/friend_controller.php';

$authController = AuthController::getInstance();
$friendController = FriendController::getInstance();

if (isset($_GET['accepted'])) {
    $user = $authController->getUserByUsername($_GET['accepted'])[0];

    $curUserId = $_SESSION['UserLogin']['id'];
    $targetUserId = $user['id'];

    $friendController->acceptFriendRequest($curUserId, $targetUserId);

    die;
}

$requests = $friendController->getFriendRequests($_SESSION['UserLogin']['id']);
$users = [];

foreach ($requests as $req) {
    $id = $req['first_user_id'];
    $user = $authController->getUserById($id);

    array_push($users, $user);
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Friend Request - Seniku</title>
    <link rel="stylesheet" href="assets/styles/style.css">
    <link rel="stylesheet" href="assets/styles/appbar.css">
    <link rel="stylesheet" href="assets/styles/friend-request.css">
</head>

<body>
    <?php include 'assets/views/components/appbar.inc'; ?>
    <main>
        <?php if (empty($users)) : ?>
            <h1 id="empty-text">You don't have friend request.</h1>
        <?php else : ?>
            <ul class="user-list">
                <?php foreach ($users as $user) : ?>
                    <li>
                        <div class="user-card">
                            <div class="left-side">
                                <img class="user-picture" src="assets/images/nophoto.jpg" alt="user picture">
                                <section class="name">
                                    <h5 class="user-main-text"><?= $user['fullname'] ?></h5>
                                    <h6 class="user-sub-text">@<?= $user['username']; ?></h6>
                                </section>
                            </div>
                            <a href="friend-request.php?accepted=<?= $user['username']; ?>" class="action-button">Accept</a>
                        </div>
                    </li>
                <?php endforeach; ?>
            </ul>
        <?php endif; ?>
    </main>
</body>

</html>