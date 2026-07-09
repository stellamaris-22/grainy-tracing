# grainy-tracing
To compile: 

`g++ Bkgd/main.cpp Bkgd/Background/Background.cpp Bkgd/Camera/Camera.cpp Bkgd/Film/Film.cpp Bkgd/API/API.cpp -o rt3` 

To run:

`./rt3 [<options>] <input_file_name>`

Only available option currently is `--help`. Our current input filename is `in.xml`. Onlyworks for `.xml` files at the moment.