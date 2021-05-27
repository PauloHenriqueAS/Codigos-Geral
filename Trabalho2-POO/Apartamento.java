package Trabalho2;

import java.util.ArrayList;
import java.io.Serializable;
public class Apartamento extends DadosImovel implements PrintDados, Serializable{
	private int andar; 
	private double valorCondominio;
	private boolean portaria24h;
	
	public Apartamento() {	}

	public Apartamento(int andar, double valorCondominio, boolean portaria24h) {
		setAndar(andar);
		setValorCondominio(valorCondominio);
		setPortaria24h(portaria24h);
	}
	
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
	
	public void mostarDados(){
		super.mostarDados();
		System.out.println("Andar: " + getAndar());
		System.out.println("Valor do condominio: "+ getValorCondominio());
		System.out.println("Portaria 24h? " + isPortaria24h());
	}
	
}
