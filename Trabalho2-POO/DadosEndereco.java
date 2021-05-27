package Trabalho2;

import java.util.ArrayList;

public class DadosEndereco {
	private ArrayList<Endereco> vetEndereco = new ArrayList<Endereco>();
	
	public void cadastrar(Endereco c) {
		this.vetEndereco.add(c);
		Persist.salvarBinario("enderecos.dat", c);//Salvar no arquivo
		System.out.println("Total de enderecos inseridos: ");
		System.out.println(this.vetEndereco.size());
	}
	
	public void listar(){
		for (Endereco objeto: this.vetEndereco) {
			objeto.mostarDados();
		}
	}
	
	public Endereco buscar(String rua) {
		Endereco c = null;
		for ( Endereco objeto: this.vetEndereco) {
			if (objeto.getRua().equals(rua)) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(String rua){
		Endereco enderecoRemove = this.buscar(rua);
		
		if(enderecoRemove != null) {
			this.vetEndereco.remove(enderecoRemove);
			return true;
		}else {
			return false;
		}
	}
}
