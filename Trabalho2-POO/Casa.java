package Trabalho2;

import java.io.Serializable;
import java.util.ArrayList;

public class Casa extends DadosImovel implements PrintDados, Serializable{
	private boolean ehCondominio;
	private boolean possuiPiscina;
	
	public Casa() {	}

	public Casa(boolean ehCondominio, boolean possuiPiscina) {
		setEhCondominio(ehCondominio);
		setPossuiPiscina(possuiPiscina);
	}
	
	public boolean isEhCondominio() {
		return ehCondominio;
	}
	public void setEhCondominio(boolean ehCondominio) {
		this.ehCondominio = ehCondominio;
	}
	public boolean isPossuiPiscina() {
		return possuiPiscina;
	}
	public void setPossuiPiscina(boolean possuiPiscina) {
		this.possuiPiscina = possuiPiscina;
	}
	
	public void mostarDados(){
		super.mostarDados();
		System.out.println("Eh condominio: " + isEhCondominio());
		System.out.println("Possui Piscina: " + isPossuiPiscina());
	}
	
	
}
