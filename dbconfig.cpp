#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
/*
	install : libmysqlclient-dev
	cmd		: mysql_config --libs
	cmd 	: mysql_config --cflags

	so		: $ g++ -o output-file $(mysql_config --cflags) test.c $(mysql_config --libs)
 */

static char* server_args[] = 
{
	"this_program",
	"--datadir=.",
	"--key_buffer_size=32M"
};

static char* server_groups[] =
{
	"embedded",
	"server",
	"this_program_SERVE",
	( char * ) NULL
};

int 
main(int argc, char const *argv[])
{
	if ( mysql_server_init ( sizeof ( server_args ) / sizeof ( char * ),
		server_args, server_groups ) )
	{
		exit ( 1 );
	}
	MYSQL* 		conn;
	MYSQL_RES* 	res;
	MYSQL_ROW  	row;
	char* 		server = "localhost";
	char*		user = "root";
	char*		password = "include";
	char* 		database = "test";

	conn = mysql_init ( NULL );
	if ( !mysql_real_connect ( conn, server, user, password,
		database, 0, NULL, 0 ) )
	{
		fprintf(stderr, "%s\n", mysql_error ( conn ));
		exit ( 1 );
	}

	if ( mysql_query ( conn, "show tables" ) )
	{
		fprintf(stderr, "%s\n", mysql_error ( conn ) );
		exit ( 1 );
	}

	res = mysql_use_result ( conn );

	printf("MYSQL Tables in mysql database:\n");

	while ( ( row = mysql_fetch_row ( res )) != NULL )
	{
		printf("%s\n", row[0]);
	}
	printf("Number of rows:  %lu\n", (unsigned long) mysql_num_rows ( res ) );

	MYSQL_FIELD* field;
	while ( ( field = mysql_fetch_field ( res ) ) )
	{
		printf("field name %s\n", field->name);
	}

	int num_fields = mysql_num_fields ( res );
	for ( int i = 0; i < num_fields; ++i )
	{
		field = mysql_fetch_field_direct ( res, i );
		printf("Field %u is %s\n", 1, field->name);
	}

	if ( !mysql_set_character_set ( conn, "utf8" ) )
	{
		MY_CHARSET_INFO cs;
		mysql_get_character_set_info ( conn, &cs );
		printf("character set information:\n");
		printf("character set name: %s\n", cs.name);
		printf("collation name: %s\n", cs.csname);
		printf("comment: %s\n", cs.comment);
		printf("directory: %s\n", cs.dir);
		printf("multi byte character min. length: %d\n", cs.mbminlen);
		printf("multi byte character max. length: %d\n", cs.mbmaxlen);
	}

	mysql_free_result ( res );
	mysql_close ( conn );
	mysql_server_end ();
	return EXIT_SUCCESS;

	return 0;
}
