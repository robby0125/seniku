<!DOCTYPE html>
<html>
<title>Seniku</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="assets/styles/admin.css">
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway">
<style>
    html,
    body,
    h1,
    h2,
    h3,
    h4,
    h5 {
        font-family: "Raleway", sans-serif
    }

    html {
        scroll-behavior: smooth;
    }
</style>

<body class="light-grey">

    <!-- Top container -->
    <div class="bar top orange large" style="z-index:4">
        <button class="bar-item button hide-large hover-none hover-text-light-grey" onclick="w3_open();"><i
                class="fa fa-bars"></i> &nbsp;Menu</button>
        <span class="bar-item right">Seniku</span>
    </div>

    <!-- Sidebar/menu -->
    <nav class="sidebar collapse white animate-left" style="z-index:3;width:300px;" id="mySidebar"><br>
        <div class="container row">
            <div class="col s4">
                <img src="assets/images/avatar2.png" class="circle margin-right" style="width:46px">
            </div>
            <div class="col s8 bar">
                <span>Welcome, <strong>zaka</strong></span><br>
            </div>
        </div>
        <hr>
        <div class="container">
            <h5>Dashboard</h5>
        </div>
        <div class="bar-block">
            <a href="#" class="bar-item button padding-16 hide-large dark-grey hover-black " onclick="w3_close()"
                title="close menu">&nbsp; Close Menu</a>
            <a href="#" class="bar-item button padding">&nbsp;
                Overview</a>
            <a href="#" class="bar-item button padding">&nbsp; Views</a>
            <a href="#" class="bar-item button padding">&nbsp; User</a>
            <a href="#" class="bar-item button padding">&nbsp; Comments</a>
            <a href="#" class="bar-item button padding">&nbsp; Log Out</a>
            <br><br>
        </div>
    </nav>


    <!-- Overlay effect when opening sidebar on small screens -->
    <div class="overlay hide-large animate-opacity" onclick="w3_close()" style="cursor:pointer"
        title="close side menu" id="myOverlay"></div>

    <!-- !PAGE CONTENT! -->
    <div class="main" style="margin-left:300px;margin-top:43px;">

        <!-- Header -->
        <header class="container" style="padding-top:22px">
            <h5><b><i class="fa fa-dashboard"></i> Dashboard</b></h5>
        </header>

        <div class="row-padding margin-bottom">
            <div class="quarter">
                <div class="container red padding-16">
                    <div class="left"><img src="assets/images/pesan.png" alt="pesan" height="100" width="100"></div>
                    <div class="right">
                        <h3>52</h3>
                    </div>
                    <div class="clear"></div>
                    <h4>Messages</h4>
                </div>
            </div>
            <div class="quarter">
                <div class="container blue padding-16">
                    <div class="left"><img src="assets/images/mata.png" alt="mata" width="120" height="100"></div>
                    <div class="right">
                        <h3>99</h3>
                    </div>
                    <div class="clear"></div>
                    <h4>Views</h4>
                </div>
            </div>
            <div class="quarter">
                <div class="container teal padding-16">
                    <div class="left"><img src="assets/images/share.png" alt="share" width="100" height="100"></div>
                    <div class="right">
                        <h3>23</h3>
                    </div>
                    <div class="clear"></div>
                    <h4>Shares</h4>
                </div>
            </div>
            <div class="quarter">
                <div class="container orange text-white padding-16">
                    <div class="left"><img src="assets/images/user.png" alt="user" width="100" height="100"></div>
                    <div class="right">
                        <h3>50</h3>
                    </div>
                    <div class="clear"></div>
                    <h4>Users</h4>
                </div>
            </div>
        </div>

        <div class="panel">
            <div class="row-padding" style="margin:0 -16px">
                <div class="third">
                    <h5>Regions</h5>
                    <img src="assets/images/region.jpeg" style="width:100%" alt="Google Regional Map">
                </div>
                <div class="twothird">
                    <h5>Feeds</h5>
                    <table class="table striped white">
                        <tr>
                            <td><i class=" text-blue large"></i></td>
                            <td>New record, over 90 views.</td>
                            <td><i>10 mins</i></td>
                        </tr>
                        <tr>
                            <td><i class=" text-red large"></i></td>
                            <td>Database error.</td>
                            <td><i>15 mins</i></td>
                        </tr>
                        <tr>
                            <td><i class=" text-yellow large"></i></td>
                            <td>New record, over 40 users.</td>
                            <td><i>17 mins</i></td>
                        </tr>
                        <tr>
                            <td><i class="text-red large"></i></td>
                            <td>New comments.</td>
                            <td><i>25 mins</i></td>
                        </tr>
                        <tr>
                            <td><i class="fa fa-share-alt text-green large"></i></td>
                            <td>New shares.</td>
                            <td><i>39 mins</i></td>
                        </tr>
                    </table>
                </div>
            </div>
        </div>
        <hr>
        <div class="container">
            <h5>General Stats</h5>
            <p>New Visitors</p>
            <div class="grey">
                <div class="container center padding green" style="width:25%">+25%</div>
            </div>

            <p>New Users</p>
            <div class="grey">
                <div class="container center padding orange" style="width:50%">50%</div>
            </div>

            <p>Bounce Rate</p>
            <div class="grey">
                <div class="container center padding red" style="width:75%">75%</div>
            </div>
        </div>
        <hr>

        <div class="container">
            <h5>indonesia</h5>
            <table class="table striped bordered border hoverable white">
                <tr>
                    <td>jawa</td>
                    <td>65%</td>
                </tr>
                <tr>
                    <td>madura</td>
                    <td>15.7%</td>
                </tr>
                <tr>
                    <td>kalimantan</td>
                    <td>5.6%</td>
                </tr>
                <tr>
                    <td>sulawesi</td>
                    <td>2.1%</td>
                </tr>
                <tr>
                    <td>papua</td>
                    <td>1.9%</td>
                </tr>
                <tr>
                    <td>brunai</td>
                    <td>1.5%</td>
                </tr>
            </table><br>
            <button class="button dark-grey">More &nbsp;<i class="fa fa-arrow-right"></i></button>
        </div>
        <hr>
        <div class="container">
            <h5 id="user">Recent Users</h5>
            <ul class="ul card-4 white">
                <li class="padding-16">
                    <img src="assets/images/avatar2.png" class="left circle margin-right" style="width:35px">
                    <span class="xlarge">zaka</span><br>
                </li>
                <li class="padding-16">
                    <img src="assets/images/avatar5.png" class="left circle margin-right" style="width:35px">
                    <span class="xlarge">zulfan</span><br>
                </li>
                <li class="padding-16">
                    <img src="assets/images/avatar6.png" class="left circle margin-right" style="width:35px">
                    <span class="xlarge">eka</span><br>
                </li>
            </ul>
        </div>
        <hr>

        <div class="container">
            <h5>Recent Comments</h5>
            <div class="row">
                <div class="col m2 text-center">
                    <img class="circle" src="assets/images/avatar3.png" style="width:96px;height:96px">
                </div>
                <div class="col m10 container">
                    <h4>fita </h4>
                    <p>Keep up the GREAT work! I am cheering for you!! Lorem ipsum dolor sit amet, consectetur
                        adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.</p><br>
                </div>
            </div>

            <div class="row">
                <div class="col m2 text-center">
                    <img class="circle" src="assets/images/avatar1.png" style="width:96px;height:96px">
                </div>
                <div class="col m10 container">
                    <h4>robby </h4>
                    <p>Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.</p><br>
                </div>
            </div>
        </div>
        <br>
        <div class="container dark-grey padding-32">
            <div class="row">
                <div class="container third">
                    <h5 class="bottombar border-green">Demographic</h5>
                    <p>Language</p>
                    <p>Country</p>
                    <p>City</p>
                </div>
                <div class="container third">
                    <h5 class="bottombar border-red">System</h5>
                    <p>Browser</p>
                    <p>OS</p>
                    <p>More</p>
                </div>
                <div class="container third">
                    <h5 class="bottombar border-orange">Target</h5>
                    <p>Users</p>
                    <p>Active</p>
                    <p>Geo</p>
                    <p>Interests</p>
                </div>
            </div>
        </div>

       
        <footer class="container padding-16 light-grey">
            <h4>FOOTER</h4>
            <p>Powered by <a href="#" target="_blank">kelompok 6</a></p>
        </footer>  
        
    </div>
     <script>
        
        var mySidebar = document.getElementById("mySidebar");

        
        var overlayBg = document.getElementById("myOverlay");

        
        function w3_open() {
            if (mySidebar.style.display === 'block') {
                mySidebar.style.display = 'none';
                overlayBg.style.display = "none";
            } else {
                mySidebar.style.display = 'block';
                overlayBg.style.display = "block";
            }
        }

        
        function w3_close() {
            mySidebar.style.display = "none";
            overlayBg.style.display = "none";
        }
    </script>

</body>

</html>
