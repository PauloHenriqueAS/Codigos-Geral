package Trabalho2;

import java.util.ArrayList;

public class DadosTranscao {
	private ArrayList<Transacao> vetTrans = new ArrayList<Transacao>();
	
	public void cadastrar(Transacao c) {
		this.vetTrans.add(c);
		Persist.salvarBinario("transacoes.dat", c);//Salvar no arquivo
		System.out.println("Total de transacões inseridas: ");
		System.out.println(this.vetTrans.size());
	}
	
	public void listar(){
		for (Transacao objeto: this.vetTrans) {
			objeto.mostarDados();
		}
	}
	
	public Transacao buscar(int nro) {
		Transacao c = null;
		for ( Transacao objeto: this.vetTrans) {
			if (objeto.getNroContrato() == nro) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(int nro){
		Transacao transRemove = this.buscar(nro);
		
		if(transRemove != null) {
			this.vetTrans.remove(transRemove);
			return true;
		}else {
			return false;
		}
	}
	
}