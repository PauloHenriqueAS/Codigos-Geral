package Trabalho2;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class Persist {
	public static void salvarBinario(String nomeArquivo, Object dado) {
		
		FileOutputStream escritorArquivo = null;
		ObjectOutputStream escritorObj = null;
		
		try {
			escritorArquivo = new FileOutputStream(nomeArquivo);
			escritorObj = new ObjectOutputStream(escritorArquivo);
			escritorObj.writeObject(dado);
			
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
		try {
			if (escritorArquivo != null) escritorArquivo.close();
		} catch (Exception e) {
			System.out.println(e.getMessage());
			}
		}
	}
	
}
