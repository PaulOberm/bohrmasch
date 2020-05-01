/*
 * A spindle class describes a spindle by its magnetic markers 
 * to count its revolutions by a sensor. 
 */
class Spindle {
  private:
    // Time intervall in ms
    unsigned int calculationTimeIntervall;
    unsigned int markerPerRevolution;

    unsigned int calculationTimeIntervallSeconds;

    /*
     * Calculate the revolutions per minute (RPM)
     * Input: 
     * revolutions - Number of revolutions
     * 
     * Output:
     * rpm - Number of revolutions per minute
     */
    unsigned int calculateRPM(float revolutions) {
      float revolutionsPerSecond = (revolutions / this->calculationTimeIntervallSeconds);
      unsigned int rpm = round(revolutionsPerSecond * 60);
      
      return rpm;
    }
  public:
    /*
     * Spindle constructor
     * Input:
     * timeIntervall - Calculation time intervall in ms
     * markers - Number of magnetic markers on the spindle
     */
    Spindle(unsigned int timeIntervall, unsigned int markers) {
      this->calculationTimeIntervall = timeIntervall;
      this->markerPerRevolution = markers;

      // To avoid repetitive transformation: Transform in seconds
      this->calculationTimeIntervallSeconds = this->calculationTimeIntervall / 1000;
      
      init();
    }

    void init() {
      Serial.println("Spindle class instancianted");
    }

    /*
     * Calculate number of revolutions per minute (RPM) for the spindle 
     * by using the summed interruptions during the calculation time.
     */
    unsigned int calculateRevolutionsPerMinute(unsigned int interruptions)
    {
      // Number of revolutions is lower or equal to the number of interruptions 
      float revolutions = interruptions / this->markerPerRevolution;

      // Calculate RPM from the deduced revolutions
      unsigned int rpm = this->calculateRPM(revolutions);
      return rpm;
    }
    
}; 
