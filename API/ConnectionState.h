enum ConnectionState {
	CREATED,	// utworzono ale jeszcze nie polaczono	
	READY,		// mozna wysylac/odbierac
	WAITING,	// czeka na dane
	SENDING,	// wysyla
	RECEIVING,	// odbiera
	CLOSED		// zamkniete
};