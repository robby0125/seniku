<?php
require_once 'connection.php';

class ContentController extends Connection
{
    private static $instance = null;

    protected function __construct()
    {
    }

    public static function getInstance() {
        if (!self::$instance) self::$instance = new ContentController();

        return self::$instance;
    }

    public function postContent($userId, $content) {

    }

    public function postContentWithImage($userId, $content, $contentImg) {
        
    }
}
