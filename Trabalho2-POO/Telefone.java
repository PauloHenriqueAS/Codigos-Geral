package Trabalho2;

import java.io.Serializable;

public class Telefone implements PrintDados, Serializable {
	private String telContato;
	private String telCelular;
	
	public Telefone () {}
	public Telefone(String tel1, String tel2) {
		setTelContato(tel1);
		setTelCelular(tel2);
	}

	public String getTelContato() {
		return telContato;
	}
	public boolean setTelContato(String telContato) {
		if(telContato.length() > 0 ) {
			this.telContato = telContato;
			return true;
		}else {
			return false;
		}
	}
	
	public String getTelCelular() {
		return telCelular;
	}
	public boolean setTelCelular(String telCelular) {
		if(telCelular.length() > 0) {
			this.telCelular = telCelular;
			return true;
		}else {
			return false;
		}
		
	}
	
	public void mostarDados(){
		System.out.println("Telefone Contato: " + getTelContato());
		System.out.println("Telefone Celular: " + getTelCelular());
	}
	
}
