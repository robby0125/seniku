<?php
/**
 * abstract class to wrapping connection object
 * this class will be extends to all of controller class
 */
abstract class Connection
{
    private $conn = null;

    /**
     * handle database connection
     * @return PDO object
     */
    public function getConnection() : PDO
    {
        if ($this->conn == null) {
            $host = 'localhost';
            $dbname = 'socmed';
            $user = 'root';

            $this->conn = new PDO("mysql:host=$host;dbname=$dbname;", $user);
        }

        return $this->conn;
    }
}
