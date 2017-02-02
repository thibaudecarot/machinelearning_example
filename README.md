**Machine learning Source Code Example**

**How to install this application ?**  

`$ git clone https://github.com/thibaudecarot/machinelearning_example.git`  
`$ cd machinelearning_example/  `  
`$ cmake .  `  
`$ make  `  

**How to execute examples?**  

`$ cd bin/`  

For Iris Prediction with KNN:  
`$ ./DataMiningExample --algo=knniris`  

For Forecast of the Forest Fire total area:   
`$ ./DataMiningExample --algo=forestfire`  

**Iris prediction with KNN** 

I provide an example to predict Iris specie with k-nearest neighbors algorithm. Iris data set is very classic problem in Data mining.
I use Euclidean distance between data. We show that the Error margin is between 4% and 12%.
To evaluate this algorithm I perform a random shuffle to split data set between learn base and test base.

Data set:  
sepalLength, sepalWidth, petalLength, petalWidth, specie;

**Predictions of burned areas with Logistic Regression** 

I use logistic regression to provide a probability of Forest Fire according to different Qualitative variables.

Attribute information:  
   For more information, read [Cortez and Morais, 2007].
   1. X - x-axis spatial coordinate within the Montesinho park map: 1 to 9
   2. Y - y-axis spatial coordinate within the Montesinho park map: 2 to 9
   3. month - month of the year: "jan" to "dec" 
   4. day - day of the week: "mon" to "sun"
   5. FFMC - FFMC index from the FWI system: 18.7 to 96.20
   6. DMC - DMC index from the FWI system: 1.1 to 291.3 
   7. DC - DC index from the FWI system: 7.9 to 860.6 
   8. ISI - ISI index from the FWI system: 0.0 to 56.10
   9. temp - temperature in Celsius degrees: 2.2 to 33.30
   10. RH - relative humidity in %: 15.0 to 100
   11. wind - wind speed in km/h: 0.40 to 9.40 
   12. rain - outside rain in mm/m2 : 0.0 to 6.4 
   13. area - the burned area of the forest (in ha): 0.00 to 1090.84 
   (this output variable is very skewed towards 0.0, thus it may make
    sense to model with the logarithm transform). 



NB: All of these examples could be quickly implemented with specific frameworks or languages like R.