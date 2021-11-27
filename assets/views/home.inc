<?php
if (isset($_POST['submit-content'])) {
    $contentTxt = $_POST['txt-content'];

    if (!empty($contentTxt)) {
        require_once 'controllers/content_controller.php';

        $contentController = ContentController::getInstance();

        $userId = $_SESSION['UserLogin']['id'];
        $username = $_SESSION['UserLogin']['username'];

        $content = $_POST['txt-content'];
        $contentImgError = $_FILES['content-img']['error'];

        if ($contentImgError != 4) {
            var_dump($_FILES);
            die;

            require_once 'utils/uploader.php';

            if (!realpath('assets/content_images/')) {
                mkdir('assets/content_images/');
            }

            if (!realpath('assets/content_images/' . $username)) {
                mkdir('assets/content_images/' . $username);
            }

            $uploader = Uploader::getInstance();

            $targetPath = 'assets/content_images/' . $username;
            $extension = explode('/', $_FILES['content-img']['type'])[1];
            $uploadName = $username . '_' . uniqid() . '.' . $extension;

            if (!$uploader->uploadImage('content-img', $targetPath, $uploadName)) {
                $contentErrMsg = $uploader->getErrorMessage();
            }
        }

        if (!isset($contentErrMsg))
            $contentController->postContent($userId, $contentTxt, isset($uploadName) ? $uploadName : null);
    } else {
        $contentErrMsg = 'Failed to publish post! make sure you fill in the post message!';
    }
}

require_once 'controllers/friend_controller.php';
require_once 'controllers/auth_controller.php';
require_once 'controllers/content_controller.php';

$user = $_SESSION['UserLogin'];

$friendIds = FriendController::getInstance()->getFriends($user['id']);
$friends = [];
$posts = [];

foreach ($friendIds as $fId) {
    $friend = AuthController::getInstance()->getUserById($fId);
    array_push($friends, $friend);

    $post = ContentController::getInstance()->getFriendContents($fId);

    if (!empty($post)) {
        $postedUser = AuthController::getInstance()->getUserById($post[0]['user_id']);
        array_push($posts, [
            'posted_user' => $postedUser,
            'post' => $post,
        ]);
    }
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home - Seniku</title>
    <link rel="stylesheet" href="assets/styles/style.css">
    <link rel="stylesheet" href="assets/styles/appbar.css">
    <link rel="stylesheet" href="assets/styles/home.css">
</head>

<body>
    <?php include 'assets/views/components/appbar.inc' ?>
    <main>
        <aside class="menus box">
            <h2 class="aside-title">Menus</h2>
            <div class="horizontal-line"></div>
            <ul>
                <li>
                    <a class="btn-menu item-spacer" href="#"><del>My Profile</del></a>
                </li>
                <li>
                    <a class="btn-menu item-spacer" href="#"><del>Notification</del></a>
                </li>
                <li>
                    <a class="btn-menu item-spacer" href="friend-request.php">Friend Request</a>
                </li>
                <li>
                    <a class="btn-menu item-spacer" href="#"><del>Edit Profile</del></a>
                </li>
                <li>
                    <a class="btn-menu" href="logout.php">Logout</a>
                </li>
            </ul>
        </aside>
        <div class="feeds">
            <?php
            if (isset($contentErrMsg)) {
                echo "<p class=\"box-error\">$contentErrMessage</p>";
            } else if (isset($_POST['submit-content'])) {
                echo "<p class=\"box-success\">Your post has been published!</p>";
            }
            ?>
            <div class="post-content box">
                <h2>Post Your Art</h2>
                <div class="horizontal-line"></div>
                <div class="margin-h8">
                    <div class="user friendtile">
                        <img src="assets/images/nophoto.jpg" alt="user picture">
                        <p><?= $user['fullname']; ?></p>
                    </div>
                    <form action="<?= $_SERVER['PHP_SELF'] ?>" method="POST" enctype="multipart/form-data">
                        <textarea name="txt-content" id="txt-content" placeholder="Type your post..."></textarea>
                        <div id="post-btn">
                            <div class="file-input-wrap">
                                <label for="add-img-content">Add image (Max. 2Mb)</label>
                                <input type="file" name="content-img" id="add-img-content">
                            </div>
                            <input type="submit" name="submit-content" id="submit-content" value="POST">
                        </div>
                    </form>
                </div>
            </div>
            <div class="horizontal-line post-divider"></div>
            <?php if (empty($posts)) : ?>
                <p class="empty-message">No Posts</p>
            <?php else : ?>
                <?php foreach ($posts as $post) : ?>
                    <?php foreach ($post['post'] as $postContent) : ?>
                        <div class="content-card box">
                            <div class="user-content margin-h8">
                                <img src="assets/images/nophoto.jpg" alt="user picture">
                                <section>
                                    <p class="name"><?= $post['posted_user']['fullname']; ?></p>
                                    <p class="post-date"><?= $postContent['published_date']; ?></p>
                                </section>
                            </div>
                            <div class="horizontal-line"></div>
                            <p class="content-text margin-h8"><?= $postContent['content']; ?></p>
                            <?php if ($postContent['content_image'] != null) : ?>
                                <img class="content-img" src="assets/content_images/<?= $post['posted_user']['username']; ?>/<?= $postContent['content_image']; ?>" alt="content image">
                            <?php endif; ?>
                        </div>
                    <?php endforeach; ?>
                <?php endforeach; ?>
            <?php endif; ?>
        </div>
        <aside class="friends box">
            <h2 class="aside-title">Friends</h2>
            <div class="horizontal-line"></div>
            <?php if (empty($friends)) : ?>
                <p class="empty-message">You don't have a friend :'</p>
            <?php else : ?>
                <?php foreach ($friends as $friend) : ?>
                    <ul>
                        <li>
                            <a class="btn-menu item-spacer" href="#">
                                <div class="user friendtile">
                                    <img src="assets/images/nophoto.jpg" alt="user picture">
                                    <p><?= $friend['fullname']; ?></p>
                                </div>
                            </a>
                        </li>
                    </ul>
                <?php endforeach; ?>
            <?php endif; ?>
        </aside>
    </main>
</body>

</html>