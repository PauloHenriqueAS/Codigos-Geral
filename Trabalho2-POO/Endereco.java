package Trabalho2;

import java.io.Serializable;

public class Endereco implements PrintDados, Serializable {
	private String rua;
	private String bairro;
	private int nro;
	private String cidade;
	private String estado;
	private String CEP;
	private String complemento;
	
	public Endereco (){	}

	public Endereco(String rua, String bairro, int nro, String cidade, String estado, String cep, String complemento) {
		setRua(rua);
		setBairro(bairro);
		setNro(nro);
		setCidade(cidade);
		setEstado(estado);
		setCEP(cep);
		setComplemento(complemento);
	}
	
	public String getRua() {
		return rua;
	}
	public boolean setRua(String rua) {
		if(rua.length() > 0) {
			this.rua = rua;	
			return true;
		}else {
			return false;
		}
	}
	public String getBairro() {
		return bairro;
	}
	public boolean setBairro(String bairro) {
		if(bairro.length() > 0) {
			this.bairro = bairro;	
			return true;
		}else {
			return false;
		}
	}
	public int getNro() {
		return nro;
	}
	public void setNro(int nro) {
		this.nro = nro;
	}
	public String getCidade() {
		return cidade;
	}
	public boolean setCidade(String cidade) {
		if(cidade.length() > 0) {
			this.cidade = cidade;	
			return true;
		}else {
			return false;
		}
	}
	public String getEstado() {
		return estado;
	}
	public boolean setEstado(String estado) {
		if(estado.length() > 0) {
			this.estado = estado;	
			return true;
		}else {
			return false;
		}
	}
	public String getCEP() {
		return CEP;
	}
	public boolean setCEP(String cep) {
		if(cep.length() > 0) {
			this.CEP = cep;	
			return true;
		}else {
			return false;
		}
	}
	public String getComplemento() {
		return complemento;
	}
	public boolean setComplemento(String complemento) {
		if(complemento.length() > 0) {
			this.complemento = complemento;	
			return true;
		}else {
			return false;
		}
	}
	
	public void mostarDados(){
		System.out.println("Rua: " + getRua());
		System.out.println("Bairro: " + getBairro());
		System.out.println("Número: " + getNro());
		System.out.println("Cidade: " + getCidade());
		System.out.println("Estado: " + getEstado());
		System.out.println("CEP: " + getCEP());
		System.out.println("Complemento: " + getComplemento());
	}
	
	
}
