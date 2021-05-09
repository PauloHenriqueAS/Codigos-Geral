package Trabalho2;

public class Casa extends DadosImovel{
	private boolean ehCondominio;
	private boolean possuiPiscina;
	
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
	
}
