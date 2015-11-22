/**
* La clase HolaMundo implementa una aplicación
* que despliega por la salida estándar “Hola Mundo”
*/
public class HolaMundo
{
	private int numero;
	
	public HolaMundo() // Constructor de clase, sin argumentos
	{
		numero = 42;	
	}
	
	public static void main(String[] args) // Metodo principal main()
	{
		// Desplegar "Hola Mundo"
		System.out.println("Hola mundoa");
		
		// Probar el funcionamiento da la API System
		String nombre;
		nombre = System.getProperty("user.name");
		System.out.println(nombre);
		
		// Probar el funcionamiento de un constructor con new()
		HolaMundo x = new HolaMundo();
		System.out.println("x.numero = " + x.numero); // 'Concatenacion' ala Python
		// No hay necesidad de free() o delete(), :D
	}
}
