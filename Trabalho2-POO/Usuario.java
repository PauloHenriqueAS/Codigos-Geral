package Trabalho2;

import java.io.Serializable;

public class Usuario extends Cliente implements PrintDados, Serializable{
	private int idImovel;

	public Usuario() {	}
	public Usuario(int idImovel) {
		setIdImovel(idImovel);
	}
	public int getIdImovel() {
		return idImovel;
	}
	public void setIdImovel(int idImovel) {
		this.idImovel = idImovel;
	}
	
	public void mostarDados(){
		super.mostarDados();
		System.out.println("Id Imovel: " + getIdImovel());
	}
}
