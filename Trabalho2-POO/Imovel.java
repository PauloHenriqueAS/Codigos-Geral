package Trabalho2;

import java.time.LocalDate;

public class Imovel {
	private int idImovel;
	private boolean disponibilidade;
	private String tipoLocacao;
	private String estadoConservacao;
	private String categoria;
	private double valor;
	private double areaMetros;
	private LocalDate dataPublicacao; //Date
	private String vendaLocacao;
	private LocalDate dataConstrucao;//Date
	
	public Imovel(){ }

	public Imovel(int id, boolean disponibilidade, String tipoLocacao, String estadoConservacao, String categoria, double valor, double areaMetros, LocalDate dataPublicacao, String vendaLocacao, LocalDate dataConstrucao) {
		setIdImovel(id);
		setDisponibilidade(disponibilidade);
		setTipoLocacao(tipoLocacao);
		setEstadoConservacao(estadoConservacao);
		setCategoria(categoria);
		setValor(valor);
		setAreaMetros(areaMetros);
		setDataPublicacao(dataPublicacao);
		setVendaLocacao(vendaLocacao);
		setDataConstrucao(dataConstrucao);
	}
	
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
	public String getTipoLocacao() {
		return tipoLocacao;
	}
	public void setTipoLocacao(String tipoLocacao) {
		this.tipoLocacao = tipoLocacao;
	}
	public String getEstadoConservacao() {
		return estadoConservacao;
	}
	public void setEstadoConservacao(String estadoConservacao) {
		this.estadoConservacao = estadoConservacao;
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
	public boolean setValor(double valor) {
		if(valor > 0) {
			this.valor = valor;
			return true;
		}else {
			return false;
		}
	}
	public double getAreaMetros() {
		return areaMetros;
	}
	public boolean setAreaMetros(double areaMetros) {
		if(areaMetros > 0) {
			this.areaMetros = areaMetros;
			return true;
		}else {
			return false;
		}
	}
	public LocalDate getDataPublicacao() {
		return dataPublicacao;
	}
	public void setDataPublicacao(LocalDate dataPublicacao) {
		this.dataPublicacao = dataPublicacao;
	}
	public String getVendaLocacao() {
		return vendaLocacao;
	}
	public void setVendaLocacao(String vendaLocacao) {
		this.vendaLocacao = vendaLocacao;
	}
	public LocalDate getDataConstrucao() {
		return dataConstrucao;
	}
	public void setDataConstrucao(LocalDate dataConstrucao) {
		this.dataConstrucao = dataConstrucao;
	}
	
	/*Metodos
	//TODO Rever!!!!!public ArrayList<String> consultarProprietario(int idImovel){}
	public ArrayList<String> pesquisarIdImovel(int idImovel){}
	public ArrayList<String> pesquisarDisponibilidade(boolean disponibilidade){}
	public ArrayList<String> pesquisarTipoLocacao(String tipoLocacao){}
	//TODO
	public ArrayList<String> pesquisarEstadoConservacao(String estadoConservacao){}
	public ArrayList<String> pesquisarCategoria(String categoria){}
	public ArrayList<String> pesquisarValor(float valor){}
	public ArrayList<String> pesquisarAreaMetros(float area){}
	public ArrayList<String> pesquisarVendaLocacao(String vendaLocacao){}
	public void atualizarValor(float novoValor, int idImovel){}
	public void cadastrarImovel(String rua, String bairro, int nro, String cidade,String cep, String complemento){}
	public void desligarImovel(int idImovel){}
	public void atualizarDisponibilidade(int idImovel){}
	*/
}