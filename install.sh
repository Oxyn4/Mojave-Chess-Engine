
#check the script is running as root

if (( $EUID != 0));
then
    printf "The Mojave-instilation script must be run as root!"
    exit
fi

printf "Beginning Mojave-Chess-Engine Isntallation \n\n"

printf "Note this script can be re-run if needed"


if test -f "bin/mojave"; then
        printf  "Found Mojave bin, Adding to path \n"

        if test -f "/usr/bin/mojave"; then
            printf "Found Mojave bin in path, Replacing"

            rm -f  /usr/bin/mojave

            cp bin/mojave /usr/bin/mojave
        else
            cp bin/mojave /usr/bin
        fi
    else
        printf "Building mojave engine" 
    
        make mojave 

         if test -f "/usr/bin/mojave"; then
            printf "Found Mojave bin in path, Replacing"

            rm -f  /usr/bin/mojave

            cp bin/mojave /usr/bin/mojave
        else
            cp bin/mojave /usr/bin
        fi
    fi
fi

