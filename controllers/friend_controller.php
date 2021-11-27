<?php
require_once 'controllers/connection.php';

/**
 * this classs will handle all of friend method
 * controller class created using singleton pattern
 */
class FriendController extends Connection {
    private static $instance = null;

    /**
     * protect the constructor method to avoid create new instance
     */
    protected function __construct()
    {
        
    }

    /**
     * get the single instance from AuthController class
     * @return FriendController object
     */
    public static function getInstance() {
        if (self::$instance == null) self::$instance = new FriendController();

        return self::$instance;
    }

    /**
     * handle friend request event
     * @param curUserId the user who request
     * @param targetUserId the user who targeted
     */
    public function addFriend($curUserId, $targetUserId) {
        $sql = 'INSERT INTO friendship (first_user_id, second_user_id, accepted) VALUES (:curUser, :targetUser, false)';
        $stmt = $this->getConnection()->prepare($sql);
        $stmt->bindValue(':curUser', $curUserId);
        $stmt->bindValue(':targetUser', $targetUserId);
        $stmt->execute();
    }

    /**
     * get all friend of the specific user by id
     * @param userId id from user
     * @return Array list of all friends
     */
    public function getFriends($userId) {
        $sql = 'SELECT * FROM friendship WHERE first_user_id = :userId OR second_user_id = :userId';
        $stmt = $this->getConnection()->prepare($sql);
        $stmt->bindValue(':userId', $userId);
        $stmt->execute();

        $friendIds = [];

        foreach ($stmt->fetchAll(PDO::FETCH_ASSOC) as $res) {
            $friendId = $res['first_user_id'] == $userId ? $res['second_user_id'] : $res['first_user_id'];
            array_push($friendIds, $friendId);
        }

        return $friendIds;
    }

    /**
     * get all friend request
     * @param userId id from user
     * @return Object list of friend request
     */
    public function getFriendRequests($userId) {
        $sql = 'SELECT first_user_id FROM friendship WHERE second_user_id = :userId AND accepted = false';
        $stmt = $this->getConnection()->prepare($sql);
        $stmt->bindValue(':userId', $userId);
        $stmt->execute();

        return $stmt->fetchAll(PDO::FETCH_ASSOC);
    }

    /**
     * event to accept the friend request
     * @param curUserId the user who logged in
     * @param targetUserId the user who request a frienship
     */
    public function acceptFriendRequest($curUserId, $targetUserId) {
        $sql = 'UPDATE friendship SET accepted = true, friendship_date = CURRENT_DATE() WHERE first_user_id = :targetUser AND second_user_id = :curUser';
        $stmt = $this->getConnection()->prepare($sql);
        $stmt->bindValue(':curUser', $curUserId);
        $stmt->bindValue(':targetUser', $targetUserId);
        $stmt->execute();
    }
}