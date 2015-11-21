# MakeFile para Java
# La primera orden espera a la segunda, porque depende de que se complete HolaMundo.class
# La segunda orden se ejecuta primero, compilando el archivo .java en una clase .class
# Luego, se ejecuta la primera orden, llamando a la VM de Java, interpretando el .class

# make -s para que sea SILENT
# make clean para que se complete solamente clean

java:	HolaMundo.class
	java HolaMundo
	
HolaMundo.class:	HolaMundo.java
	javac HolaMundo.java
	
clean:
	rm HolaMundo.class
