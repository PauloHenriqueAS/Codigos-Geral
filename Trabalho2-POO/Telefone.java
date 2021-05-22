package Trabalho2;

public class Telefone {
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
	
	
	/*Metodos
	public void cadastrarTelefone(String tel1, String tel2){
		setTelContato(tel1);
		setTelCelular(tel2);
	}*/
}
