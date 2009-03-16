 CREATE TABLE `heimweh_documents` (
`id` INT NOT NULL ,
`date` DATETIME NOT NULL ,
`xml` LONGTEXT NOT NULL ,
PRIMARY KEY ( `id` ) ,
INDEX ( `date` ) ,
FULLTEXT (
`xml`
)
) ENGINE = MYISAM ;


 CREATE TABLE `heimweh_metadata` (
`mid` INT NOT NULL AUTO_INCREMENT PRIMARY KEY ,
`subject` TEXT NOT NULL ,
`predicate` TEXT NOT NULL ,
`object` LONGTEXT NOT NULL ,
FULLTEXT (
`subject` ,
`predicate` ,
`object`
)
) ENGINE = MYISAM ;

