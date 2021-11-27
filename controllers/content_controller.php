<?php
require_once 'connection.php';

/**
 * this classs will handle all of content method
 * controller class created using singleton pattern
 */
class ContentController extends Connection
{
    private static $instance = null;

    /**
     * protect the constructor method to avoid create new instance
     */
    protected function __construct()
    {
    }

    /**
     * get the single instance from AuthController class
     * @return ContentController object
     */
    public static function getInstance() {
        if (!self::$instance) self::$instance = new ContentController();

        return self::$instance;
    }

    /**
     * execute the SQL Syntaxt to add content to database
     * @param userId id from the user who posted
     * @param content content text
     * @param contentImg? content image, can't be null 
     */
    public function postContent($userId, $content, $contentImg = null) {
        $sql = 'INSERT INTO post (user_id, content, content_image, published_date) VALUES (:userId, :content, :contentImg, CURRENT_TIMESTAMP())';

        $stmt = $this->getConnection()->prepare($sql);
        $stmt->bindValue(':userId', $userId);
        $stmt->bindValue(':content', $content);
        $stmt->bindValue(':contentImg', $contentImg);
        $stmt->execute();
    }

    /**
     * get all content of connected friends
     * @param friendId friend id
     * @return Object all content from the friend
     */
    public function getFriendContents($friendId) {
        $sql = 'SELECT * FROM post WHERE user_id = :friendId';
        $stmt = $this->getConnection()->prepare($sql);
        $stmt->bindValue(':friendId', $friendId);
        $stmt->execute();

        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }
}
