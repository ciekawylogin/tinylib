/*#include <openssl/applink.c> // To prevent crashing (see the OpenSSL FAQ)
#include <openssl/bio.h> // BIO objects for I/O
#include <openssl/ssl.h> // SSL and SSL_CTX for SSL connections
#include <openssl/err.h> // Error reporting

#include <stdio.h> // If you don't know what this is for stop reading now.

const char * USER_NAME = "Wojtek";
const char * PASSWORD = "123";

int main(int argc, char** argv) {
	CRYPTO_malloc_init(); // Initialize malloc, free, etc for OpenSSL's use
	SSL_library_init(); // Initialize OpenSSL's SSL libraries
	SSL_load_error_strings(); // Load SSL error strings
	ERR_load_BIO_strings(); // Load BIO error strings
	OpenSSL_add_all_algorithms(); // Load all available encryption algorithms

	SSL_load_error_strings();
	OpenSSL_add_all_ciphers();
	OpenSSL_add_all_digests();
	(void)SSL_library_init(); // always succeeds per man page

	const SSL_METHOD *meth = TLSv1_client_method();
	SSL_CTX *ctx = SSL_CTX_new(meth);
	SSL_CTX_set_options(ctx, SSL_OP_ALL | SSL_OP_NO_SSLv2);
	SSL_CTX_SRP_CTX_init(ctx);

	const char *cipherlist = "ALL:NULL";
	if (SSL_CTX_set_cipher_list(ctx, cipherlist) != 1)
		printf("SSL_CTX_set_cipher_list failed");

	if (SSL_CTX_set_srp_username(ctx, (char *)USER_NAME) != 1)
		printf("SSL_CTX_set_srp_username failed");

	if (SSL_CTX_set_srp_password(ctx, (char *)PASSWORD) != 1)
		printf("SSL_CTX_set_srp_password failed");

	if (SSL_CTX_set_srp_strength(ctx, 1024) != 1)
		printf("SSL_CTX_set_srp_strength failed");

	SSL *ssl = SSL_new(ctx);
	if (ssl == NULL)
		printf("SSL_new failed");

	//if (SSL_set_fd(ssl, sock) != 1)
		printf("SSL_set_fd failed\n");
		system("pause");

	int rc = SSL_connect(ssl);

	return 0;
}

*/