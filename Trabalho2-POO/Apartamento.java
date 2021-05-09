package Trabalho2;

public class Apartamento extends DadosImovel{
	private int andar; 
	private double valorCondominio;
	private boolean portaria24h;
	
	public int getAndar() {
		return andar;
	}
	public void setAndar(int andar) {
		this.andar = andar;
	}
	public double getValorCondominio() {
		return valorCondominio;
	}
	public void setValorCondominio(double valorCondominio) {
		this.valorCondominio = valorCondominio;
	}
	public boolean isPortaria24h() {
		return portaria24h;
	}
	public void setPortaria24h(boolean portaria24h) {
		this.portaria24h = portaria24h;
	}
	
}
