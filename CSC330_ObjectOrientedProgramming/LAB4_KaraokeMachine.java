package edu.cuny.csi.csc330.lab4;
import java.util.*;
import java.util.Arrays;
import edu.cuny.csi.csc330.util.*;

public class KaraokeMachine {
	
	public static class Songs{
		public final static int MAX_SELECTION = 5;
		
		//chosen top 15 songs in 2010
		public final static String[] songNames = {
				"Tik Tok", 
				"Need You Now",
				"Hey, Soul Sister", 
				"California Gurls (feat. Snoop Dog)",
				"OMG",
				"Airplanes (feat. Hayley Williams)",
				"Love the Way You Lie (feat. Rihanna)",
				"Bad Romance",
				"Dynamite", 
				"Break Your Heart (feat. Ludacris)",
				"Nothin' On You",
				"I Like It (feat. Pitbull)",
				"BedRock (feat. Lloyd)",
				"In My Head",
				"Rude Boy"				
		};
		
		// the artist name corresponds with the songNames (example songName[0] has the artist aritstName[0])
		public final static String[] artistNames = {
				"Ke$ha",
				"Lady Antebellum",
				"Train",
				"Katy Perry",
				"Usher",
				"B.o.B",
				"Eminem",
				"Lady Gaga",
				"Taio Cruz",
				"Taio Cruz",
				"B.o.B",
				"Enrique Iglesias",
				"Young Money",
				"Jason Derulo",
				"Rihanna",
		};
		
		public static String[] generatePreset() {
			//create a preset array and put random songs inside
			//return the list and output that list.
			String [] preset = new String[MAX_SELECTION];
			for(int i = 0; i<preset.length; i++) {
				int num = Randomizer.generateInt(0,songNames.length - 1);
				preset[i] = "["+ (i+1) + "] " + songNames[num] + " by " + artistNames[num];
			}
			return preset;
		}
//		public void string SongList(){
//			
//		}
	}
	
	//constants
	protected static final int MIN_VOLUME = 0;
	protected static final int MAX_VOLUME = 100;
	protected static final int DEFAULT_VOLUME = 50;
	protected static final int MIN_BATTERY = 0;
	protected static final int MAX_BATTERY = 100;
	protected static final int MIN_MIC_VOLUME = 0;
	protected static final int DEFAULT_MIC_VOLUME = 50;
	protected static final int MAX_MIC_VOLUME = 100;
	protected static final int MAX_FAVORITE_SONGS = 3;
	
	//object instance properties
	private boolean powerState;
	private int volume;
	private boolean on;
	private boolean micOn;
	private int micVolume;
	private int batteryNum;
	private String[] songSelection; //this will get music selection from inner class
	private String selectedSong;
	private String[] favoriteSong;
	private boolean isCharging;
	private boolean firstTimeOn;
	
	public KaraokeMachine() {
		init();
	}
	
	public void init() {
		firstTimeOn = false;
	}
	
	public void on() {
		powerState = true;
		if(firstTimeOn == false) {
			volume = DEFAULT_VOLUME;
			micVolume = DEFAULT_MIC_VOLUME;
			micOn = true;
			songSelection = Songs.generatePreset();
			batteryNum = 100;
			firstTimeOn = true;
		}
	} // end of on()
	
	public void selectASong(int selectionNum) { //user must select a song from 1-5
		selectedSong = songSelection[selectionNum - 1];
	} //end of selectASong(int)
	
	public void favoriteSong(boolean favorite) {
		if(favorite == true) {
			if(selectedSong != null && favoriteSong == null) {
				favoriteSong = new String[MAX_FAVORITE_SONGS]; //users can only have a max of 3 favorite songs
				favoriteSong[0] = selectedSong;
			}
			else if(selectedSong != null && favoriteSong != null){
				for(int i = 0; i < MAX_FAVORITE_SONGS; i++) {
					if(favoriteSong[i] == null) {
						favoriteSong[i] = selectedSong;
						i = MAX_FAVORITE_SONGS;
					}
				}
			}
		}
	} // end of favoriteSong
	
	public void off() {
		selectedSong = null;
		powerState = false;
	}
	
	public int getMicVolume() {
		return micVolume;
	}

	public void setMicVolume(int micVolume) {
		this.micVolume = micVolume;
	}
	public boolean isPowerState() {
		return powerState;
	}

	public void setPowerState(boolean powerState) {
		this.powerState = powerState;
	}

	public int getVolume() {
		return volume;
	}

	public void setVolume(int volume) {
		this.volume = volume;
	}

	public boolean isOn() {
		return on;
	}

	public void setOn(boolean on) {
		this.on = on;
	}

	public boolean isMicOn() {
		return micOn;
	}

	public void setMicOn(boolean micOn) {
		this.micOn = micOn;
	}

	public int getBatteryNum() {
		return batteryNum;
	}

	public String[] getSongSelection() {
		return songSelection;
	}

	public boolean isFirstTimeOn() {
		return firstTimeOn;
	}
	
	public String getSelectedSong() {
		return selectedSong;
	}

	public boolean isCharging() {
		return isCharging;
	}

	public void setCharging(boolean isCharging) {
		this.isCharging = isCharging;
	}

@Override
	public String toString() {
		return "PowerState=" + powerState + " selectedVolume=" + volume + " micOn=" + micOn + " micVolume=" + micVolume + " batteryLevel=" + batteryNum
				+ " isCharging=" + isCharging
				+ "\nFavorite songs = " + Arrays.toString(favoriteSong)
				+ "\nSong Selection = "  + Arrays.toString(songSelection)
				+ "\nSelected Song = " + selectedSong;
	}
	public static void main(String[] args) {
		KaraokeMachine obj = new KaraokeMachine();
		System.out.print("New instance:\n");
		System.out.println(obj);
		
		System.out.print("\n\nTurned on:\n");
		obj.on();
		System.out.println(obj);
		
		System.out.print("\n\nSelecting Volume and start charging the device:\n");
		obj.setVolume(90);
		obj.setCharging(true);
		System.out.println(obj);
		
		System.out.print("\n\nSelecting a song:\n");
		obj.selectASong(2);
		System.out.println(obj);

		System.out.print("\n\nSetting favorite song:\n");
		obj.favoriteSong(true);
		System.out.println(obj);
		
		System.out.print("\n\nSelecting a song AND setting favorite song:\n");
		obj.selectASong(4);
		obj.favoriteSong(true);
		System.out.println(obj);
		
		System.out.print("\n\nTurn off:\n");
		obj.off();
		System.out.println(obj);
		
	
	}

}
