/*
#include <openssl/bio.h> // BIO objects for I/O
#include <openssl/ssl.h> // SSL and SSL_CTX for SSL connections
#include <openssl/err.h> // Error reporting

#include <stdio.h> // If you don't know what this is for stop reading now.

const char * USER_NAME = "Wojtek";
const char * PASSWORD = "123";

void initOpenSSL() {

	SSL_load_error_strings();
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();
	(void)SSL_library_init(); // always succeeds per man page

}

int main(int argc, char** argv) {

	initOpenSSL();
	

	//  const SSL_METHOD *meth = SSLv23_server_method();

	const SSL_METHOD *meth = TLSv1_server_method();
	SSL_CTX *ctx = SSL_CTX_new(meth);
	SSL_CTX_set_options(ctx, SSL_OP_ALL | SSL_OP_NO_SSLv2);
	SSL_CTX_SRP_CTX_init(ctx);

	const char *cipherlist = "ALL:NULL";
	if (SSL_CTX_set_cipher_list(ctx, cipherlist) != 1)
		printf("SSL_CTX_set_cipher_list failed");

	SSL *ssl = SSL_new(ctx);
	if (ssl == NULL) {
		printf("SSL_new() failed");
	}

	//if (SSL_set_fd(ssl, sock) != 1)
		//printf("SSL_set_fd failed");

	if (SSL_set_srp_server_param_pw(ssl, USER_NAME, PASSWORD, "1024") != 1)
		printf("SSL_set_srp_server_param_pw failed");

	int rc = SSL_accept(ssl);

	system("pause");
	return 0;
}
*/
