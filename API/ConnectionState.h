enum ConnectionState {
	CREATED,			// utworzono ale jeszcze nie polaczono	
	READY,				// mozna wysylac/odbierac
	WAITING,			// czeka na dane
	SYNC_SENDING,		// wysyla dane synchronicznie
	SYNC_RECEIVING,		// odbiera dane synchronicznie
	ASYNC_SENDING,		// wysyla dane asynchronicznie
	ASYNC_RECEIVING,	// odbiera dane asynchronicznie
	CLOSED				// polaczenie zamkniete
};