package Trabalho2;

public class Imovel {
	private int idImovel;
	private boolean disponibilidade;
	private String tipoLocação;
	private String estadoConservação;
	private String categoria;
	private double valor;
	private double areaMetros;
	private float dataPublicação; //Date
	private String vendaLocação;
	private float dataConstrução;//Date
	
	public int getIdImovel() {
		return idImovel;
	}
	public void setIdImovel(int idImovel) {
		this.idImovel = idImovel;
	}
	public boolean isDisponibilidade() {
		return disponibilidade;
	}
	public void setDisponibilidade(boolean disponibilidade) {
		this.disponibilidade = disponibilidade;
	}
	public String getTipoLocação() {
		return tipoLocação;
	}
	public void setTipoLocação(String tipoLocação) {
		this.tipoLocação = tipoLocação;
	}
	public String getEstadoConservação() {
		return estadoConservação;
	}
	public void setEstadoConservação(String estadoConservação) {
		this.estadoConservação = estadoConservação;
	}
	public String getCategoria() {
		return categoria;
	}
	public void setCategoria(String categoria) {
		this.categoria = categoria;
	}
	public double getValor() {
		return valor;
	}
	public void setValor(double valor) {
		this.valor = valor;
	}
	public double getAreaMetros() {
		return areaMetros;
	}
	public void setAreaMetros(double areaMetros) {
		this.areaMetros = areaMetros;
	}
	public float getDataPublicação() {
		return dataPublicação;
	}
	public void setDataPublicação(float dataPublicação) {
		this.dataPublicação = dataPublicação;
	}
	public String getVendaLocação() {
		return vendaLocação;
	}
	public void setVendaLocação(String vendaLocação) {
		this.vendaLocação = vendaLocação;
	}
	public float getDataConstrução() {
		return dataConstrução;
	}
	public void setDataConstrução(float dataConstrução) {
		this.dataConstrução = dataConstrução;
	}
	
	
}