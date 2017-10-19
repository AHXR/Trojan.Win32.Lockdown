<?php

/*
	@title
		AHXRScreenLock
	@author
		AHXR (https://github.com/AHXR)
	@copyright
		2017
	AHXRScreenLock is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
    
	AHXRScreenLock is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
    
	You should have received a copy of the GNU General Public License
	along with AHXRScreenLock.  If not, see <http://www.gnu.org/licenses/>.
*/
//=======================================================

header('Content-Type: application/json');
require( "settings.php" );

$a_build = "";

if( $_POST['functionname'] == "buildFile" ) {
    
    $s_new_file = "downloads/" . $_POST['arguments'][ 2 ] . ".exe";

    if( copy( $FILE_STUB, $s_new_file ) ) {
        $s_password = hash( $FILE_HASH, $_POST['arguments'][ 0 ] );
        $s_password = $FILE_OPEN . $s_password . $FILE_CLOSE;
        
        $s_message = $FILE_OPEN . $_POST['arguments'][ 1 ] . $FILE_CLOSE;
        
        file_put_contents( $s_new_file, $s_password . $s_message, FILE_APPEND );
        $a_build = "Your file has been generated.";
    }
    else
        $a_build = "There was an error generating your file.";
}

echo json_encode($a_build);

?>