package Trabalho2;

import java.util.ArrayList;

public class DadosPessoaIndicadora {
	private ArrayList<PessoaIndicadora> vetPessoaIndicadora = new ArrayList<PessoaIndicadora>();
	
	public void cadastrar(PessoaIndicadora c) {
		this.vetPessoaIndicadora.add(c);
		Persist.salvarBinario("pessoasIndicadoras.dat", c);//Salvar no arquivo
		System.out.println("Total de pessoas indicadoras inseridas: ");
		System.out.println(this.vetPessoaIndicadora.size());
	}
	
	public void listar(){
		for (PessoaIndicadora objeto: this.vetPessoaIndicadora) {
			objeto.mostarDados();
		}
	}
	
	public PessoaIndicadora buscar(String nome) {
		PessoaIndicadora c = null;
		for ( PessoaIndicadora objeto: this.vetPessoaIndicadora) {
			if (objeto.getNome().equals(nome)) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(String nome){
		PessoaIndicadora indicadorRemove = this.buscar(nome);
		
		if(indicadorRemove != null) {
			this.vetPessoaIndicadora.remove(indicadorRemove);
			return true;
		}else {
			return false;
		}
	}
}
