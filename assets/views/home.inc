<?php 
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
                <p><?= $user['fullname']; ?></p>
                <img src="https://images.unsplash.com/photo-1503023345310-bd7c1de61c7d?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1365&q=80" alt="user picture">
            </div>
        </nav>
    </header>
    <main>
        <aside class="menus">
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
            <p>
                Lorem ipsum dolor sit amet consectetur adipisicing elit. Mollitia dicta necessitatibus aliquid a suscipit doloremque est nobis cupiditate et cumque quaerat deserunt officiis fugit eius, itaque voluptatibus iste voluptatum. Porro, temporibus dolorem repellendus nemo, tempore blanditiis rem iusto tenetur nam expedita vitae sunt deserunt consequatur asperiores quia dicta? Consequuntur aut in ducimus suscipit quasi eaque dolor deserunt consequatur recusandae iusto, est aperiam et voluptatem distinctio accusantium quibusdam mollitia deleniti neque quod. Iste repellendus doloremque, voluptatem recusandae obcaecati eius vero quod nihil, itaque dicta veniam mollitia exercitationem optio necessitatibus sint odio eum ipsum? Accusantium laboriosam vitae enim quod omnis ipsum? Eligendi modi quisquam quae aperiam tempora accusamus odit consectetur quam illum sint autem nostrum ab, officia porro magnam ullam? Necessitatibus iure quibusdam esse molestias modi, magnam tenetur aspernatur laborum a corporis perspiciatis quo delectus, nulla laudantium odio optio reiciendis quaerat quae. Architecto itaque, cum praesentium optio maiores tenetur molestiae ducimus, dolorum enim minus blanditiis ea aperiam rem quia sunt nihil officiis ipsa nulla eligendi? Iste, voluptas nisi non quaerat laborum, modi optio nam voluptatibus neque accusantium amet. Nihil, ex sapiente officiis vero inventore quaerat, expedita, nobis cumque cupiditate consectetur excepturi molestias et impedit quibusdam quasi. Cupiditate iure perspiciatis illum debitis consequatur facere quibusdam natus pariatur, quam iusto id necessitatibus ipsam eaque maiores, vitae commodi, consequuntur placeat voluptate? Fugit facere natus voluptate, ducimus eos incidunt corporis reprehenderit illum tempora in voluptatum, ratione atque ad nesciunt neque quod dolorem. Natus fugit repellat, quis nobis inventore dolore quibusdam voluptate. Porro, saepe! Facilis, voluptates. Voluptas dolorum laborum odio tempora voluptatibus consequatur ea iure inventore. Cupiditate vitae nulla placeat dolore id iste nobis magni aperiam quam eaque commodi porro, provident earum sint possimus? Obcaecati voluptas sit, dolorum dolore doloribus officiis ut facilis explicabo dolor fuga dolores suscipit! Et dicta dolorum reiciendis, enim quaerat voluptatum qui, quia aperiam sit ipsa est nobis in ea illum iure eveniet libero nesciunt, corrupti reprehenderit inventore facere? Repellendus nobis amet consequatur fugiat quisquam dolore quae ut qui maxime? Consequatur, dicta ducimus tenetur voluptatum velit ipsa veniam fuga nostrum mollitia ullam illo id. Exercitationem eligendi officiis sit? Tenetur ab consequatur, sed, perferendis vitae totam quasi, eveniet saepe rerum quo doloremque molestiae aperiam nam! Veniam, ex modi itaque reprehenderit eum perspiciatis suscipit alias, vitae minus, fugiat at sit quasi adipisci. Cumque magnam ipsa dolor inventore, esse eius consectetur accusantium quasi laudantium adipisci alias repudiandae eveniet amet at. Officiis omnis, veritatis in dicta beatae, ratione nam alias assumenda mollitia provident consectetur expedita deserunt eveniet inventore iure minima maxime, cumque sint culpa perferendis? Assumenda nobis facere dolorum, aperiam adipisci vitae amet, ipsa ea officiis excepturi quidem et cum pariatur asperiores esse sunt aut fuga possimus, necessitatibus consequuntur. Maiores quas modi adipisci, sit odio soluta laboriosam veritatis error eveniet. Consectetur error, enim, sit ipsam perspiciatis quos voluptate iste animi repudiandae eligendi, atque distinctio voluptatum similique numquam officiis aliquam? Modi repellat accusantium voluptatibus cumque repudiandae sequi et harum culpa reprehenderit, cupiditate, amet soluta. Distinctio doloremque aperiam, numquam, maiores quam asperiores sit omnis at consectetur consequatur voluptatum iste similique recusandae neque totam eveniet fugit, pariatur aliquam! Numquam rerum id veniam accusamus perspiciatis excepturi repellat voluptatum delectus. Sit excepturi animi impedit autem vitae fuga recusandae earum, quibusdam commodi tempora odit esse corrupti vel et facere eveniet non natus repellendus, molestiae, cumque nostrum veniam illum mollitia voluptatem? Quidem consequuntur pariatur, adipisci impedit doloribus recusandae corporis commodi, beatae quisquam repudiandae laborum assumenda quae suscipit deserunt enim ea accusamus facere? Facilis sed consequuntur sunt illo. Deleniti officiis, inventore repudiandae voluptatibus omnis ratione explicabo? Error iusto sapiente molestias minus nemo odio sint, est earum repudiandae veniam, debitis beatae explicabo ad laborum sit. Consequuntur tempora nostrum officiis eum obcaecati consequatur aliquam quasi blanditiis, facere debitis magni fuga odit a dolorem incidunt nobis mollitia ratione. Ad similique praesentium inventore labore nemo nam id reprehenderit iure commodi sint illo debitis itaque, in earum ipsum fuga, temporibus aperiam, sunt ratione? Fugit aspernatur maxime eum praesentium neque quaerat aperiam dolorem doloribus quia harum aut delectus cum, voluptatibus repellat molestiae ad dolor exercitationem architecto explicabo id? Dolore corrupti saepe delectus. Dolor iure quas nihil quidem nam praesentium. Voluptates, animi. Quibusdam voluptate consequatur, laudantium repellendus dolores ratione ipsam quo, explicabo veritatis nemo odio illum quia nobis. Ex voluptatibus dolorum minima nulla accusantium velit expedita, incidunt placeat quis nesciunt dolore voluptas sit! Cumque soluta, expedita tempora excepturi aliquid a voluptas distinctio tenetur. Non explicabo blanditiis ad alias odio tempore id magnam magni ipsa, reiciendis inventore facere, eos illo ab repellendus ullam dicta enim fugiat soluta maiores eius perspiciatis at quaerat asperiores? Inventore libero fugit in quod qui optio reiciendis ducimus non porro quas reprehenderit officiis asperiores aliquid voluptatum laudantium quibusdam hic laborum, natus dolorum similique. Repudiandae accusantium temporibus earum, ab explicabo architecto labore ea, omnis illum nemo libero ad, veritatis esse sapiente modi suscipit. Sequi vitae expedita debitis qui nesciunt sint consequuntur repudiandae! Aut sunt nam dicta delectus cupiditate nesciunt corrupti veritatis quas reprehenderit, possimus unde cumque. Quo dolorum libero perspiciatis praesentium eligendi architecto asperiores atque amet facilis optio consequuntur possimus a, totam, magni autem nulla obcaecati accusantium inventore, sed eveniet quia beatae. Similique veniam ea maxime velit voluptatem sunt modi officiis id quasi voluptate culpa quos laudantium aut cum voluptates, autem deleniti repellendus eaque quam nihil beatae. Obcaecati dolore odit molestias ipsum, iusto unde qui optio expedita magni laudantium alias voluptatum perferendis soluta a repellat iste totam doloribus? A est aliquid atque optio sit eius natus delectus esse fugit alias? Esse quos expedita ipsa, facilis dignissimos excepturi quo, quasi, cupiditate minima ipsum temporibus possimus officiis? Ab in voluptate cupiditate voluptatibus veritatis expedita harum libero natus nesciunt, voluptatem impedit perferendis, provident magni odit voluptates accusamus officia esse tempore, sapiente aut. Distinctio ducimus ullam expedita ut similique ex provident consectetur amet architecto harum quis sint alias velit rem facere vel, modi cumque magni id repellendus minima. Eos, quia? Facere unde atque et quam vitae odit? Temporibus quis omnis itaque rem? Delectus beatae labore ipsam commodi temporibus ullam quam voluptatem ex quas repellendus fugiat ad, corporis doloribus molestias necessitatibus eos sit officia assumenda?
            </p>
        </div>
        <aside class="friends">
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