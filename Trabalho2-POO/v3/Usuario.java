package Trabalho2;

public class Usuario extends Cliente{
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
		System.out.println("Id Imovel: " + getIdImovel());
	}
}
