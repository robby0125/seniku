<?php
abstract class Connection
{
    private $conn = null;

    protected function __construct()
    {
    }

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
