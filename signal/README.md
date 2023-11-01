#### sigterm
> example of execute
> > ```
> > ./sigterm
> > Process running. PID: 39155
> > ```
> send signal
> > ```kill 39155``
> catch signal and exit with a failure status (EXIT_FAILURE)
> > ```
> > Received SIGTERM signal. Terminating the process.
> > echo $?
> > 1
> > ```
