<?php
class Uploader {
    private static $instance = null;

    private $errMessage = '';

    protected function __construct()
    {
        
    }

    public static function getInstance() {
        if (!self::$instance) self::$instance = new Uploader();

        return self::$instance;
    }

    public function uploadImage($key, $targetPath, $uploadedName) {
        $type = explode('/', $_FILES[$key]['type']);

        if ($type[0] != 'image') {
            $this->errMessage = 'The uploaded file is not an image';
            return false;
        }

        $size = $_FILES[$key]['size'];
        $tmpName = $_FILES[$key]['tmp_name'];

        if ($size > 2097152) {
            $this->errMessage = 'Uploaded image size is too big. (Max. 2Mb)';
            return false;
        }

        move_uploaded_file($tmpName, $targetPath . '/' . $uploadedName);

        return true;
    }

    public function getErrorMessage() {
        return $this->errMessage;
    }
}