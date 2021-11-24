<?php
if (isset($_POST['submit-content'])) {
    $content = $_POST['txt-content'];
    $contentImgError = $_FILES['content-img']['error'];

    if ($contentImgError != 4) {
        require_once 'utils/uploader.php';

        $username = $_SESSION['UserLogin']['username'];

        if (!realpath('assets/content_images/')) {
            mkdir('assets/content_images/');
        }

        if (!realpath('assets/content_images/' . $username)) {
            mkdir('assets/content_images/' . $username);
        }

        $targetPath = 'assets/content_images/' . $username;

        $uploader = Uploader::getInstance();
        if ($uploader->uploadImage('content-img', $targetPath, $username . uniqid())) {
            // do something
        } else {
            echo $uploader->errMessage;
        }
    }

    die;
}

$user = $_SESSION['UserLogin'];
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home - Seniku</title>
    <link rel="stylesheet" href="assets/styles/style.css">
    <link rel="stylesheet" href="assets/styles/home.css">
</head>

<body>
    <header>
        <nav>
            <h1>Seniku</h1>
            <form class="search-user-form" action="" method="GET">
                <input type="text" name="username" id="username" placeholder="Search username...">
                <button type="submit">
                    <img src="assets/icons/search-solid.png" alt="Search Icon">
                </button>
            </form>
            <div class="user">
                <p><?= explode(' ', $user['fullname'])[0]; ?></p>
                <img src="https://images.unsplash.com/photo-1503023345310-bd7c1de61c7d?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1365&q=80" alt="user picture">
            </div>
        </nav>
    </header>
    <main>
        <aside class="menus box">
            <h2 class="aside-title">Menus</h2>
            <div class="horizontal-line"></div>
            <ul>
                <li>
                    <a class="btn-menu item-spacer" href="#">My Profile</a>
                </li>
                <li>
                    <a class="btn-menu item-spacer" href="#">Notification</a>
                </li>
                <li>
                    <a class="btn-menu item-spacer" href="#">Friend Request</a>
                </li>
                <li>
                    <a class="btn-menu item-spacer" href="#">Edit Profile</a>
                </li>
                <li>
                    <a class="btn-menu" href="logout.php">Logout</a>
                </li>
            </ul>
        </aside>
        <div class="feeds">
            <div class="post-content box">
                <h2>Post Your Art</h2>
                <div class="horizontal-line"></div>
                <div class="margin-h8">
                    <div class="user friendtile">
                        <img src="https://images.unsplash.com/photo-1503023345310-bd7c1de61c7d?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1365&q=80" alt="user picture">
                        <p>User Name</p>
                    </div>
                    <form action="<?= $_SERVER['PHP_SELF'] ?>" method="POST" enctype="multipart/form-data">
                        <textarea name="txt-content" id="txt-content" placeholder="Type your post..."></textarea>
                        <div id="post-btn">
                            <div class="file-input-wrap">
                                <label for="add-img-content">Add image</label>
                                <input type="file" name="content-img" id="add-img-content" value="Add image">
                            </div>
                            <input type="submit" name="submit-content" id="submit-content" value="POST">
                        </div>
                    </form>
                </div>
            </div>
            <div class="horizontal-line"></div>
            <p>No Posts</p>
        </div>
        <aside class="friends box">
            <h2 class="aside-title">Friends</h2>
            <div class="horizontal-line"></div>
            <ul>
                <li>
                    <a class="btn-menu item-spacer" href="#">
                        <div class="user friendtile">
                            <img src="https://images.unsplash.com/photo-1503023345310-bd7c1de61c7d?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1365&q=80" alt="user picture">
                            <p>User Name</p>
                        </div>
                    </a>
                </li>
            </ul>
        </aside>
    </main>
</body>

</html>