package Trabalho2;

import java.util.ArrayList;

public class Casa extends DadosImovel{
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
	
						/*Metodos
	public ArrayList<String> pesquisarCondominio(boolean condominio){
	}
	public ArrayList<String> pesquisarPiscina(boolean piscina){
		/*Comparable<piscina>;
		compareTo();
	}*/
}
